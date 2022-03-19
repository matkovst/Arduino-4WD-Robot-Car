/*
 * ultrasonic.h
 *
 * Slightly modified Ultrasonic library (https://github.com/ErickSimoes/Ultrasonic)
 */

#ifndef ultrasonic_h
#define ultrasonic_h

/*
 * Values of divisors
 */
#define CM 28
#define INC 71

class Ultrasonic {
  public:
	Ultrasonic() = default;
    Ultrasonic(uint8_t sigPin) : Ultrasonic(sigPin, sigPin) {};
    Ultrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeOut = 20000UL);
    unsigned int read(uint8_t und = CM);
    unsigned int distanceRead(uint8_t und = CM) __attribute__ ((deprecated ("This method is deprecated, use read() instead.")));
    void setTimeout(unsigned long timeOut) {timeout = timeOut;}
	
	void setup(uint8_t trigPin, uint8_t echoPin, unsigned long timeOut = 20000UL);

  private:
    uint8_t trig;
    uint8_t echo;
    boolean threePins = false;
    unsigned long previousMicros;
    unsigned long timeout;
    unsigned int timing();
};

#endif // ultrasonic_h
