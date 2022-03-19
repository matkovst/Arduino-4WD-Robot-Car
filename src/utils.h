#ifndef utils_h
#define utils_h

#define RESULT_OK 0
#define RESULT_FAILED 1

#define MIN_LED_DELAY 10.0f
#define MAX_LED_DELAY 2500.0f
#define MIN_USONIC_DIST_CM 2.0f
#define MAX_USONIC_DIST_CM 400.0f

struct result_t
{
    int code = 0;
    String msg = "";
  
    result_t() = default;
  
    result_t(int code, const String& msg)
        : code(code)
        , msg(msg)
    {}
};

static int ledDelayForDistance(int distance)
{
    const float usonicRange = MAX_USONIC_DIST_CM - MIN_USONIC_DIST_CM;
    const float relativeDistance = distance / usonicRange;
    const float delayRange = MAX_LED_DELAY - MIN_LED_DELAY;
    return (MIN_LED_DELAY + relativeDistance * delayRange);
}

#endif // utils_h