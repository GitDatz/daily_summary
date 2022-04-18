#include "../src/model/Data.hpp"
#include <gtest/gtest.h>

#include <functional>
#include <string>

class DataTest: public ::testing::Test {
protected:
    void SetUp() override {
        mData = std::make_unique<model::Data>(mDateString);
    }

    void TearDown() override {
        mData.reset();
    }
    const std::string mDateString = "2022-02-22";
    std::unique_ptr<model::Data> mData;
};

TEST_F(DataTest, DateStringTest)
{
    const std::string EXPECTED_DATE_STRING = "2022-02-22";
    ASSERT_EQ(EXPECTED_DATE_STRING, mData->GetDateString());
}

TEST_F(DataTest, AddTaskTest)
{
    const int EXPECTED_NUMBER_OF_TASKS = 5;
    for (int i = 0; i < EXPECTED_NUMBER_OF_TASKS; i++) {
        const std::string task("Task " + std::to_string(i));
        mData->AddTask(task);
    }
    ASSERT_EQ(mData->GetTaskVector().size(), EXPECTED_NUMBER_OF_TASKS);
}

TEST_F(DataTest, DeleteTaskTest)
{
    const int INITIAL_NUMBER_OF_TASKS = 5;
    for (int i = 0; i < INITIAL_NUMBER_OF_TASKS; i++) {
        const std::string task("Task " + std::to_string(i));
        mData->AddTask(task);
    }
    ASSERT_EQ(mData->GetTaskVector().size(), INITIAL_NUMBER_OF_TASKS);
    const int NUMBER_OF_DELETED_TASKS = 3;
    for (int i = 0; i < NUMBER_OF_DELETED_TASKS; i++) {
        mData->DeleteTask(i);
    }
    const int FINAL_NUMBER_OF_TASKS =
        INITIAL_NUMBER_OF_TASKS - NUMBER_OF_DELETED_TASKS;
    ASSERT_EQ(mData->GetTaskVector().size(), FINAL_NUMBER_OF_TASKS);
}
