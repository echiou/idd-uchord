    #include "mbed.h"
    #include "DebounceIn.h"
    #include <string>
    #include <sstream>

     

    DigitalOut myled(LED2);

    DigitalIn buttonDot1(D11);
    DigitalIn buttonDot2(D10);
    DigitalIn buttonDot3(D9);
    DigitalIn buttonDot4(D8);
    DigitalIn buttonDash1(D7);
    DigitalIn buttonDash2(D6);
    DigitalIn buttonDash3(D5);
    DigitalIn buttonDash4(D4);
    DebounceIn buttonEnter(D2);
    
    Serial pc(USBTX, USBRX);

    // SPST Pushbutton demo using internal PullUp function

    // no external PullUp resistor needed

    // Pushbutton from D2 to GND.

    int main() {

        int oldButtonEnter=0;
        int newButtonEnter;
        wait(.001);
        
        buttonEnter.mode(PullUp);
        buttonDot1.mode(PullUp);
        buttonDot2.mode(PullUp);
        buttonDot3.mode(PullUp);
        buttonDot4.mode(PullUp);
        buttonDash1.mode(PullUp);
        buttonDash2.mode(PullUp);
        buttonDash3.mode(PullUp);
        buttonDash4.mode(PullUp);

        while(1) {
            newButtonEnter = buttonEnter;
            
            int letter = 0;

            if (!buttonDot1 && buttonDash1) {
                letter += 1;
            } else if (buttonDot1 && !buttonDash1) {
                letter += 2;
            }
            
            if (!buttonDot2 && buttonDash2) {
                letter += 10;
            } else if (buttonDot2 && !buttonDash2) {
                letter += 20;
            }
            
            if (!buttonDot3 && buttonDash3) {
                letter += 100;
            } else if (buttonDot3 && !buttonDash3) {
                letter += 200;
            }
            
            if (!buttonDot4 && buttonDash4) {
                letter += 1000;
            } else if (buttonDot4 && !buttonDash4) {
                letter += 2000;
            }
            if ((newButtonEnter==0) && (oldButtonEnter==1)) {
                std::string letterToPrint = "";
                
                switch(letter) {
                    case(0): letterToPrint = " "; break;
                    case(21): letterToPrint = "a"; break; //.-
                    case(1112): letterToPrint = "b"; break; //-...
                    case(1212): letterToPrint = "c"; break; //-.-.
                    case(112): letterToPrint = "d"; break; //-..
                    case(1): letterToPrint = "e"; break; //.
                    case(1211): letterToPrint = "f"; break; //..-.
                    case(122): letterToPrint = "g"; break; //--.
                    case(1111): letterToPrint = "h"; break; //....
                    case(11): letterToPrint = "i"; break; //..
                    case(2221): letterToPrint = "j"; break; //.---
                    case(212): letterToPrint = "k"; break; //-.-
                    case(1121): letterToPrint = "l"; break; //.-..
                    case(22): letterToPrint = "m"; break; //--
                    case(12): letterToPrint = "n"; break; //-.
                    case(222): letterToPrint = "o"; break; //---
                    case(1221): letterToPrint = "p"; break; //.--.
                    case(2122): letterToPrint = "q"; break; //--.-
                    case(121): letterToPrint = "r"; break; //.-.
                    case(111): letterToPrint = "s"; break; //...
                    case(2): letterToPrint = "t"; break; //-
                    case(211): letterToPrint = "u"; break; //..-
                    case(2111): letterToPrint = "v"; break; //...-
                    case(221): letterToPrint = "w"; break; //.--
                    case(2112): letterToPrint = "x"; break; //-..-
                    case(2212): letterToPrint = "y"; break; //-.--
                    case(1122): letterToPrint = "z"; break; //--..
                }
                  pc.printf(letterToPrint.c_str());
            }
            myled = buttonEnter;
            oldButtonEnter = newButtonEnter;
        }
    }