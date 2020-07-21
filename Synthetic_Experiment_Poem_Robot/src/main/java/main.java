import java.io.*;
import java.util.Scanner;

import okhttp3.*;

public class main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        System.out.println("Type in the url of image:");
        String imgurl = in.nextLine();
        System.out.println("For example: https://oss.neko.ooo/index.php/s/jHYPmwBwagK7nX7/download");
        OkHttpClient client = new OkHttpClient().newBuilder()
                .build();
        MediaType mediaType = MediaType.parse("application/x-www-form-urlencoded");
        RequestBody body = RequestBody.create(mediaType, "url=" + imgurl);
        Request request = new Request.Builder()
                .url("https://aip.baidubce.com/rest/2.0/ocr/v1/general_basic?access_token=\"24.339976495f735186d88e5e52f732d616.2592000.1597913963.282335-21507330\"")
                .method("POST", body)
                .addHeader("Content-Type", "application/x-www-form-urlencoded")
                .build();
        Response response = client.newCall(request).execute();
        System.out.println(response.body().string());
    }
}
