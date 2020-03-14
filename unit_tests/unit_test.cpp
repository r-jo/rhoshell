#include "gtest/gtest.h"
#include "../header/Base.h"
#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include "../header/Parser.h"
#include "../header/TestCommand.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

TEST(AndTest, AndgetCommand) {
    string cmd = "ls && ls";
    Command *test = new Command(cmd);
    EXPECT_EQ(test->getCommand(), "ls && ls");
}
TEST(OrTest, OrgetCommand) {
    string cmd = "ls || ls";
    Command *test = new Command(cmd);
    EXPECT_EQ(test->getCommand(), "ls || ls");
}
TEST(SemicolonTest, SemicolongetCommand) {
    string cmd = "ls ; ls";
    Command *test = new Command(cmd);
    EXPECT_EQ(test->getCommand(), "ls ; ls");
}
TEST(CommandTest, CommandgetCommand){
    string cmd = "ls";
    Command *test = new Command(cmd);
    EXPECT_EQ(test->getCommand(), "ls");
}
TEST(getCommandTest, TestgetCommand){
    string cmd1 = "touch tempBin";
    string cmd2 = "touch -e tempBin";
    Base* test1 = new Command(cmd1);
    Base* test2 = new Command(cmd2);
    test1->execute();
    EXPECT_TRUE(test2->execute());
    Base* remove = new Command("rm -f tempBin");
    remove->execute();
}
TEST(ParenTest, ParenthesesTest) {
  string cmd1 = "(ls)";
  string cmd2 = "(ls; echo hello world)";
  Base *test1 = new Command(cmd1);
  Base *test2 = new Command(cmd2);
  EXPECT_TRUE(test1->execute());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
