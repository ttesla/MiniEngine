#ifndef SINGLETON_H
#define SINGLETON_H

namespace MiniEngine
{
    template<typename T>

    /// <summary>
    /// Template class for all Singletons
    /// </summary>
    class Singleton
    {
    public:
        static T* GetInstance();

    protected:
        Singleton() {}
        ~Singleton() {}
        void Destroy();

        static T* mInstance;

    private:
        // Disable copy constructor and assignment
        Singleton(const Singleton<T>&) = delete;
        Singleton& operator =(const Singleton&) = delete;
    };

    template<typename T>
    T* Singleton<T>::GetInstance()
    {
        if (mInstance == nullptr)
        {
            mInstance = new T();
        }

        return mInstance;
    }

    template<typename T>
    void Singleton<T>::Destroy()
    {
        if (mInstance != nullptr)
        {
            delete mInstance;
            mInstance = nullptr;
        }
    }

    template<typename T>
    T* Singleton<T>::mInstance = nullptr;
}

#endif // SINGLETON_H
