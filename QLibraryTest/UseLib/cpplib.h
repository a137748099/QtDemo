#ifndef CPPLIB_H
#define CPPLIB_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define Q_DECL_EXPORT __declspec(dllexport)
#  define Q_DECL_IMPORT __declspec(dllimport)
#else
#  define Q_DECL_EXPORT     __attribute__((visibility("default")))
#  define Q_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(CPPLIB_LIBRARY)
#  define CPPLIB_EXPORT Q_DECL_EXPORT
#else
#  define CPPLIB_EXPORT Q_DECL_IMPORT
#endif

class CppLib
{
public:
    virtual ~CppLib();

    virtual int add(int a, int b) = 0;
};

class CPPLIB_EXPORT TestLib : public CppLib
{
public:
    virtual ~TestLib();

    int add(int a, int b) override;

};

extern "C" {
CPPLIB_EXPORT int MyAdd(int a, int b);

CPPLIB_EXPORT void *createCppLib();
}

#endif // CPPLIB_H
