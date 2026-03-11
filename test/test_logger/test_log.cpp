#include <unity.h>
#include <log.h>
#include <string>

#ifdef ARDUINO
#include <Arduino.h>
#endif


void setUp(void)
{
}

void tearDown(void)
{
}


void test_timestamp_format(void)
{
    std::string ts = logger.timestamp();

    TEST_ASSERT_TRUE(!ts.empty());
    TEST_ASSERT_TRUE(ts.front() == '[');
    TEST_ASSERT_TRUE(ts.back() == ']');
}


void test_logger_functions(void)
{
    logger.info("Info test");
    logger.success("Success test");
    logger.warn("Warn test");
    logger.error("Error test");
    logger.debug("Debug test");

    TEST_ASSERT_TRUE(true);
}


int runUnityTests(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_timestamp_format);
    RUN_TEST(test_logger_functions);

    return UNITY_END();
}


#ifdef ARDUINO

void setup(void)
{
    Serial.begin(115200);
    delay(2000);

    runUnityTests();
}

void loop(void)
{
}

#else

int main(void)
{
    return runUnityTests();
}

#endif