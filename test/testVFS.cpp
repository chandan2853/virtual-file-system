#include "./gtest/gtest.h"
#include "../inc/iCommand.h"
#include "../src/commandParser.cpp"
#include "../src/commandList.cpp"
#include "../inc/virtualFileSystemComponents.h"

std::shared_ptr<VirtualFileSystem> filesystem = std::make_shared<VirtualFileSystem>();
CommandParser parse;
TEST(testCommand, provideWrongCommandGivesFalse )
{
    bool result = parse.commandParse("mk kfjh",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testCommand, provideCorrectCommandGivesTrue )
{
    bool result = parse.commandParse("help",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testMkdirCommand, creatingSingleDirectoryWhichNotExistsGivesTrue )
{
    bool result = parse.commandParse("mkdir data",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testMkdirCommand, creatingMultipleDirectoryWhichNotExistsGivesTrue )
{
    bool result = parse.commandParse("mkdir music directory1 directory2",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testMkdirCommand, creatingSingleDirectoryWhichExistsGivesFalse )
{
    bool result = parse.commandParse("mkdir data",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testCdCommand, changeToDirectoryWhichNotExistsGivesFalse )
{
    bool result = parse.commandParse("cd system",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testCdCommand, changeToDirectoryWhichExistsGivesTrue )
{
    bool result = parse.commandParse("cd data",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testCdCommand, changeToPreviousDirectoryGivesTrue )
{
    bool result = parse.commandParse("cd ..",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testCdCommand, changeToRootDirectoryGivesTrue )
{
    bool result = parse.commandParse("cd",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testTouchCommand, creatingFileWhichNotExistGivesTrue )
{
    bool result = parse.commandParse("touch file.txt file1.txt",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testTouchCommand, creatingFileWhichExistGivesFalse )
{
    bool result = parse.commandParse("touch file1.txt",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testRmCommand, deletingFileWhichNotExistGivesFalse )
{
    bool result = parse.commandParse("rm file6.txt",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testRmCommand, deletingFileWhichExistGivesTrue )
{
    bool result = parse.commandParse("rm file1.txt",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testRmCommand, deletingDirectoryGivesFalse )
{
    bool result = parse.commandParse("rm file1.txt",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testRmdirCommand, deletingDirectoryWhichNotExistGivesFalse )
{
    bool result = parse.commandParse("rmdir datadir",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testRmdirCommand, deletingDirectoryWhichExistGivesTrue )
{
    bool result = parse.commandParse("rmdir data",filesystem);
    ASSERT_EQ(result, true);
}

TEST(testRmdirCommand, deletingFileGivesFalse )
{
    bool result = parse.commandParse("rmdir file.txt",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testLsCommand, GivingExtraArgumentInCommandGivesFalse )
{
    bool result = parse.commandParse("ls l",filesystem);
    ASSERT_EQ(result, false);
}

TEST(testLsCommand, GivingNoArgumentInCommandGivesTrue )
{
    bool result = parse.commandParse("ls",filesystem);
    ASSERT_EQ(result, true);
}



int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}