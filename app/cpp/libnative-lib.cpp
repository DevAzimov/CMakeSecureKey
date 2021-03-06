#include <jni.h>
#include <string>

std::string getData(int x) {
    std::string app_secret = "Null";

    if (x == 1)
        app_secret = "api_private_key"; //The first key that you want to protect against decompilation
    if (x == 2)
        app_secret = "api_public_key";   //The second key that you want to protect against decompilation

    // The number of parameters to be protected can be increased.

    return app_secret;
}

extern "C" jstring
Java_com_magicapp_cmakesecurekey_MainActivity_getApiKey(
        JNIEnv *env,
        jobject /* this */,
        jint id) {
    std::string app_secret = "Null";
    app_secret = getData(id);
    return env->NewStringUTF(app_secret.c_str());
}