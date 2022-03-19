#ifndef head_h
#define head_h

#include <Servo.h>
#include "ultrasonic.h"
#include "utils.h"

class Head final
{
public:

    Head() = default;

    ~Head()
    {
	    m_servo.detach();
    }
  
    void setup(uint8_t usonicTrigPin, uint8_t usonicEchoPin, int servoPin)
    {
        m_usonic.setup(usonicTrigPin, usonicEchoPin);
        m_servo.attach(servoPin);
    }
  
    result_t check()
    {
        int resCode = 0;
        String resMsg = "";
        
        /* Check servo */
        m_servo.write(180); delay(500);
        m_servo.write(0); delay(500);
        const bool servoOk = true;
        if (!servoOk)
        {
            resCode = 1;
        resMsg += "Head servo failed";
        }
        
        /* Check Ultrasonic */
        const bool usonicOk = (m_usonic.read() != 0);
        if (!usonicOk)
        {
            resCode = 1;
        resMsg += ", Head ultrasonic failed";
        }
        
        return {resCode, resMsg};
    }
    
    int observe()
    {
        m_distance = m_usonic.read(); delay(40);
        return m_distance;
    }
    
    int distance() const noexcept
    {
        return m_distance;
    }

private:
    Ultrasonic m_usonic;
    Servo m_servo;
    int m_distance { 0 };
};

#endif // head_h