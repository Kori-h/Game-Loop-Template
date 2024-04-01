#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include "../pch.hpp"
#include "../Singleton/singleton.hpp"

namespace core 
{
    enum 
    {
        MAX_KEYS = 256
    };

    enum KeyCode
    {
        KEYCODE_A = 'A',
        KEYCODE_SPACE = ' ',
        KEYCODE_ESCAPE = 27
    };

    class InputHandler : public core::Singleton<InputHandler>
    {
        private:
            std::bitset<MAX_KEYS> current_keys;
            std::bitset<MAX_KEYS> previous_keys;
            
        public:
            InputHandler(void);
            bool GetKeyTriggered(KeyCode key_code) const;
            bool GetKeyDown(KeyCode key_code) const;
            bool GetKeyUp(KeyCode key_code) const;
            void Update(void);
    };
}
#endif //!__INPUT_HANDLER__