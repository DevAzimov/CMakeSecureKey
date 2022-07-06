package com.magicapp.cmakesecurekey

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log

class MainActivity : AppCompatActivity() {

    init {
        System.loadLibrary("native-lib")
    }

    external fun getApiKey(id: Int): String?

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val privateKey = getApiKey(1)
        val publicKey = getApiKey(2)

        Log.d("TAG", "privateKey: $privateKey")
        Log.d("TAG", "publicKey: $publicKey")
    }
}