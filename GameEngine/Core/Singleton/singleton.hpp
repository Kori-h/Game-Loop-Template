#ifndef __SINGLETON__
#define __SINGLETON__

namespace core 
{
    template<typename T>
    class Singleton
    {
        public:
            static T& GetInstance(void)
            {
                static T instance;
                return instance;
            }
    };
}

#endif //!__SINGLETON__