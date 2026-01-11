#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("Niuhaipeng, Nihao!", 0, 10),std::string("Niuhaipeng"));
    EXPECT_EQ(StringUtils::Slice("Niuhaipeng, Nihao!", -6, -1),std::string("Nihao"));
    EXPECT_EQ(StringUtils::Slice("Niuhaipeng, Nihao!", 12, 0),std::string("Nihao!"));
    EXPECT_EQ(StringUtils::Slice("Niuhaipeng, Nihao!", 20, 25),std::string(""));
    EXPECT_EQ(StringUtils::Slice("Niuhaipeng, Nihao!", 10, 5),std::string(""));
    EXPECT_EQ(StringUtils::Slice("", 0, 5),std::string(""));
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("niuhaipeng"),std::string("Niuhaipeng"));
    EXPECT_EQ(StringUtils::Capitalize("nIUHAIPENG"),std::string("Niuhaipeng"));
    EXPECT_EQ(StringUtils::Capitalize(""),std::string(""));
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("niuhaipeng"),std::string("NIUHAIPENG"));
    EXPECT_EQ(StringUtils::Upper("NIUHAIPENG"),std::string("NIUHAIPENG"));
    EXPECT_EQ(StringUtils::Upper(""),std::string(""));
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("NIUHAIPENG"),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::Lower("niuhaipeng"),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::Lower(""),std::string(""));
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("  niuhaipeng"),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::LStrip("niuhaipeng  "),std::string("niuhaipeng  "));
    EXPECT_EQ(StringUtils::LStrip("  niuhaipeng  "),std::string("niuhaipeng  "));
    EXPECT_EQ(StringUtils::LStrip(""),std::string(""));
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("  niuhaipeng"),std::string("  niuhaipeng"));
    EXPECT_EQ(StringUtils::RStrip("niuhaipeng  "),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::RStrip("  niuhaipeng  "),std::string("  niuhaipeng"));
    EXPECT_EQ(StringUtils::RStrip(""),std::string(""));
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip("  niuhaipeng  "),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::Strip(""),std::string(""));
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("niuhaipeng", 16, ' '),std::string("   niuhaipeng   "));
    EXPECT_EQ(StringUtils::Center("niuhaipeng", 16, '0'),std::string("000niuhaipeng000"));
    EXPECT_EQ(StringUtils::Center("niuhaipeng", 10, ' '),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::Center("", 5, ' '),std::string("     "));
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("niuhaipeng", 16, ' '),std::string("niuhaipeng      "));
    EXPECT_EQ(StringUtils::LJust("niuhaipeng", 16, '0'),std::string("niuhaipeng000000"));
    EXPECT_EQ(StringUtils::LJust("niuhaipeng", 10, ' '),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::LJust("", 5, ' '),std::string("     "));
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("niuhaipeng", 16, ' '),std::string("      niuhaipeng"));
    EXPECT_EQ(StringUtils::RJust("niuhaipeng", 16, '0'),std::string("000000niuhaipeng"));
    EXPECT_EQ(StringUtils::RJust("niuhaipeng", 10, ' '),std::string("niuhaipeng"));
    EXPECT_EQ(StringUtils::RJust("", 5, ' '),std::string("     "));
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("niuhaipeng", "i", "I"),std::string("nIuhaIpeng"));
    EXPECT_EQ(StringUtils::Replace("niuhaipeng", "ip", "IP"),std::string("niuhaIPeng"));
    EXPECT_EQ(StringUtils::Replace("niuhaipeng", "", "X"),std::string("XnXiXuXhXaXiXpXeXnXgX"));
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split("", " "),std::vector<std::string>({}));
    EXPECT_EQ(StringUtils::Split("niuhaipeng nihao", " "),std::vector<std::string>({"niuhaipeng", "nihao"}));
    EXPECT_EQ(StringUtils::Split("niuhaipeng nihao", ""),std::vector<std::string>({"n", "i", "u", "h", "a", "i", "p", "e", "n", "g", " ", "n", "i", "h", "a", "o"}));
    EXPECT_EQ(StringUtils::Split("niuhaipeng,nihao,", ","),std::vector<std::string>({"niuhaipeng", "nihao", ""}));
}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(" ", {"niuhaipeng", "nihao"}),std::string("niuhaipeng nihao"));
    EXPECT_EQ(StringUtils::Join("", {"n", "i", "h", "a", "o"}),std::string("nihao"));
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(StringUtils::ExpandTabs("", 4),std::string(""));
    EXPECT_EQ(StringUtils::ExpandTabs("niuhaipeng\tnihao", 4),std::string("niuhaipeng  nihao"));
    EXPECT_EQ(StringUtils::ExpandTabs("\tniuhaipeng\tnihao", 4),std::string("    niuhaipeng  nihao"));
    EXPECT_EQ(StringUtils::ExpandTabs("niuhaipeng\tnihao", 0),std::string("niuhaipeng\tnihao"));
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("niuhaipeng", "nihao"), 6);
    EXPECT_EQ(StringUtils::EditDistance("niuhaipeng", "niuhaipeng"), 0);
    EXPECT_EQ(StringUtils::EditDistance("", ""), 0);
    EXPECT_EQ(StringUtils::EditDistance("Niuhaipeng", "niuhaipeng", true), 0);
}
