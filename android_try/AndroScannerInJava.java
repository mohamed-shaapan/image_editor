package aha.androscanner;

import android.media.MediaScannerConnection;
import android.os.Bundle;

public class AndroScannerInJava extends org.qtproject.qt5.android.bindings.QtActivity
{
    public static MediaScannerConnection s_mMs;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        System.out.println("in the activity");

        super.onCreate(savedInstanceState);

        s_mMs = new MediaScannerConnection(getApplicationContext(), null);
        s_mMs.connect();

    }

    public static void scanForPicture(String name)
    {
        System.out.print("scan for picture -> ");
        System.out.println(name);

        s_mMs.scanFile(name, null);
    }
}
