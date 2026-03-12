#include <unity.h>
#include <string>

#include "log.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

static void log_test_case(const char* testName, const char* description)
{
    logger.printRaw("==================================================");
    logger.info("Running test: %t", green(testName));
    logger.printRaw(description);
    logger.printRaw("==================================================");
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_timestamp_should_be_wrapped_in_brackets(void)
{
    log_test_case(
        "test_timestamp_should_be_wrapped_in_brackets",
        "Validates that timestamp output starts with '[' and ends with ']'."
    );

    const std::string ts = logger.timestamp();

    TEST_ASSERT_FALSE(ts.empty());
    TEST_ASSERT_EQUAL('[', ts.front());
    TEST_ASSERT_EQUAL(']', ts.back());
}

void test_info_should_accept_plain_message(void)
{
    log_test_case(
        "test_info_should_accept_plain_message",
        "Validates that logger.info accepts a plain message."
    );

    logger.info("Info test");
    TEST_PASS();
}

void test_success_should_accept_plain_message(void)
{
    log_test_case(
        "test_success_should_accept_plain_message",
        "Validates that logger.success accepts a plain message."
    );

    logger.success("Success test");
    TEST_PASS();
}

void test_warn_should_accept_plain_message(void)
{
    log_test_case(
        "test_warn_should_accept_plain_message",
        "Validates that logger.warn accepts a plain message."
    );

    logger.warn("Warn test");
    TEST_PASS();
}

void test_error_should_accept_plain_message(void)
{
    log_test_case(
        "test_error_should_accept_plain_message",
        "Validates that logger.error accepts a plain message."
    );

    logger.error("Error test");
    TEST_PASS();
}

void test_debug_should_accept_plain_message(void)
{
    log_test_case(
        "test_debug_should_accept_plain_message",
        "Validates that logger.debug accepts a plain message."
    );

    logger.debug("Debug test");
    TEST_PASS();
}

void test_info_should_accept_formatted_message(void)
{
    log_test_case(
        "test_info_should_accept_formatted_message",
        "Validates formatted placeholders with logger.info."
    );

    logger.info("Info %t %t", magenta("hello"), blue("world"));
    TEST_PASS();
}

void test_success_should_accept_formatted_message(void)
{
    log_test_case(
        "test_success_should_accept_formatted_message",
        "Validates formatted placeholders with logger.success."
    );

    logger.success("Success %t", green("ok"));
    TEST_PASS();
}

void test_warn_should_accept_formatted_message(void)
{
    log_test_case(
        "test_warn_should_accept_formatted_message",
        "Validates formatted placeholders with logger.warn."
    );

    logger.warn("Warn %t", yellow("careful"));
    TEST_PASS();
}

void test_error_should_accept_formatted_message(void)
{
    log_test_case(
        "test_error_should_accept_formatted_message",
        "Validates formatted placeholders with logger.error."
    );

    logger.error("Error %t", red("failed"));
    TEST_PASS();
}

void test_debug_should_accept_formatted_message(void)
{
    log_test_case(
        "test_debug_should_accept_formatted_message",
        "Validates formatted placeholders with logger.debug."
    );

    logger.debug("Debug %t", magenta("trace"));
    TEST_PASS();
}

void test_printRaw_should_accept_plain_message(void)
{
    log_test_case(
        "test_printRaw_should_accept_plain_message",
        "Validates that logger.printRaw accepts a plain message."
    );

    logger.printRaw("Plain raw message");
    TEST_PASS();
}

void test_printRaw_should_accept_formatted_message(void)
{
    log_test_case(
        "test_printRaw_should_accept_formatted_message",
        "Validates formatted placeholders with logger.printRaw."
    );

    logger.printRaw("Raw %t %t", magenta("hello"), blue("world"));
    TEST_PASS();
}

void test_testLogColors_should_execute_without_failure(void)
{
    log_test_case(
        "test_testLogColors_should_execute_without_failure",
        "Validates that testLogColors executes fully without failures."
    );

    logger.testLogColors();
    TEST_PASS();
}

int runUnityTests(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_timestamp_should_be_wrapped_in_brackets);

    RUN_TEST(test_info_should_accept_plain_message);
    RUN_TEST(test_success_should_accept_plain_message);
    RUN_TEST(test_warn_should_accept_plain_message);
    RUN_TEST(test_error_should_accept_plain_message);
    RUN_TEST(test_debug_should_accept_plain_message);

    RUN_TEST(test_info_should_accept_formatted_message);
    RUN_TEST(test_success_should_accept_formatted_message);
    RUN_TEST(test_warn_should_accept_formatted_message);
    RUN_TEST(test_error_should_accept_formatted_message);
    RUN_TEST(test_debug_should_accept_formatted_message);

    RUN_TEST(test_printRaw_should_accept_plain_message);
    RUN_TEST(test_printRaw_should_accept_formatted_message);

    RUN_TEST(test_testLogColors_should_execute_without_failure);

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