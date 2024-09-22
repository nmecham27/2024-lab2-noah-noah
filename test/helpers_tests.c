#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "helpers.h"

void setUp(void) {}

void tearDown(void) {}

void test_character_output()
{
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");

    char testCharacter;
    //Convert a sequence of lower case characters
    testCharacter = 'h';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'H', getchar(), "Failed h" );

    testCharacter = 'e';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'E', getchar(), "Failed e" );

    testCharacter = 'l';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'L', getchar(), "Failed l" );

    testCharacter = 'l';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'L', getchar(), "Failed l, 2" );

    testCharacter = 'o';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'O', getchar(), "Failed o" );


    //Convert a sequence of upper case characters
    testCharacter = 'W';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'w', getchar(), "Failed W" );

    testCharacter = 'O';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'o', getchar(), "Failed O" );

    testCharacter = 'R';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'r', getchar(), "Failed R" );

    testCharacter = 'L';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'l', getchar(), "Failed L" );

    testCharacter = 'D';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( 'd', getchar(), "Failed D" );

    //Convert a non alphabet character
    testCharacter = '&';
    character_convert( testCharacter );
    TEST_ASSERT_EQUAL_CHAR_MESSAGE( '&', getchar(), "Failed &" );
}

void test_blink_step(void)
{
    int testCount = 0;
    bool testLedState = false;

    // Verify that test count increments, but testLedState stays the same
    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 1, testCount, "Failed count 1" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 1" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 2, testCount, "Failed count 2" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)true, (int)testLedState, "Failed LED check 2" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 3, testCount, "Failed count 3" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 3" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 4, testCount, "Failed count 4" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)true, (int)testLedState, "Failed LED check 4" );
    
    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 5, testCount, "Failed count 5" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 5" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 6, testCount, "Failed count 6" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)true, (int)testLedState, "Failed LED check 6" );


    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 7, testCount, "Failed count 7" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 7" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 8, testCount, "Failed count 8" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)true, (int)testLedState, "Failed LED check 8" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 9, testCount, "Failed count 9" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 9" );
    
    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 10, testCount, "Failed count 10" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)true, (int)testLedState, "Failed LED check 10" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 11, testCount, "Failed count 11" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 11" );

    blink_step( &testCount, &testLedState );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 12, testCount, "Failed count 12" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( (int)false, (int)testLedState, "Failed LED check 12" );
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_character_output);
    RUN_TEST(test_blink_step);
    sleep_ms(5000);
    return UNITY_END();
}
