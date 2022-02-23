#include <gtest/gtest.h>
#include "header.h"

TEST(uTest, smallTest)
{

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
