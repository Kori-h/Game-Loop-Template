#include "input_handler.hpp"

namespace core 
{
    InputHandler::InputHandler(void)
    {
        for (int i{}; i < MAX_KEYS; ++i)
        {
            previous_keys[i] = current_keys[i] = false;
        }
    }

    bool InputHandler::GetKeyTriggered(KeyCode key_code) const
    {
        return current_keys.test(key_code) && previous_keys.test(key_code) == false;
    }

    bool InputHandler::GetKeyDown(KeyCode key_code) const
    {
        return current_keys.test(key_code);
    }

    bool InputHandler::GetKeyUp(KeyCode key_code) const
    {
        return current_keys.test(key_code) == false && previous_keys.test(key_code);
    }

    void InputHandler::Update(void)
    {
        previous_keys = current_keys;

        current_keys.reset();

        while (_kbhit())
        {
            int key = _getch();

            if (key >= 0 && key < MAX_KEYS)
            {
                if (key >= 'a' && key <= 'z') 
                {
                    key += 'A' - 'a';
                }

                current_keys.set(key);
            }
        }
    }
}