#include "../src/controller/Controller.hpp"
#include "../src/model/Data.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <functional>
#include <string>

class MockData : public model::Data {
public:
    MOCK_METHOD(void, AddTask, (const std::string), (override));
    MOCK_METHOD(void, DeleteTask, (const int), (override));
    MOCK_METHOD(void, SaveToFile, (), (override));
};

class ControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
        mMockDataPtr = std::make_unique<MockData>();
    }

    void TearDown() override {
    }
    std::unique_ptr<MockData> mMockDataPtr;
};

TEST_F(ControllerTest, AddTaskTest)
{
    auto& mock_data_ref = *mMockDataPtr;
    const std::string EXPECTED_TASK = "Task";
    auto controller = controller::Controller(std::move(mMockDataPtr));

    EXPECT_CALL(mock_data_ref, AddTask(EXPECTED_TASK)).Times(2);
    controller.AddTask(EXPECTED_TASK);
    controller.AddTask(EXPECTED_TASK);
}

TEST_F(ControllerTest, DeleteTaskTest)
{
    auto& mock_data_ref = *mMockDataPtr;
    const std::string EXPECTED_TASK = "Task";
    auto controller = controller::Controller(std::move(mMockDataPtr));

    EXPECT_CALL(mock_data_ref, AddTask(EXPECTED_TASK)).Times(1);
    controller.AddTask(EXPECTED_TASK);

    EXPECT_CALL(mock_data_ref, DeleteTask(0)).Times(1);
    controller.DeleteTask(0);
}

TEST_F(ControllerTest, SaveToFileTest)
{
    auto& mock_data_ref = *mMockDataPtr;
    const std::string EXPECTED_TASK = "Task";
    auto controller = controller::Controller(std::move(mMockDataPtr));

    EXPECT_CALL(mock_data_ref, SaveToFile()).Times(1);
    controller.SaveToFile();
}
