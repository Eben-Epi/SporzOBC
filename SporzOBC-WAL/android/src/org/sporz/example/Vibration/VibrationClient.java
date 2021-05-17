package org.sporz.example.Vibration;

import android.content.Context;
import android.os.Vibrator;
import android.app.Activity;
import android.os.Bundle;

public class VibrationClient extends org.qtproject.qt5.android.bindings.QtActivity
{

public static Vibrator m_vibrator;
public static VibrationClient m_istance;

public VibrationClient()
{
m_istance = this;
}

public static void start(int x)
{
if (m_vibrator == null)
{
if (m_istance != null)
{
m_vibrator = (Vibrator) m_istance.getSystemService(Context.VIBRATOR_SERVICE);
m_vibrator.vibrate(x);
}

   }
   else m_vibrator.vibrate(x);
}
}