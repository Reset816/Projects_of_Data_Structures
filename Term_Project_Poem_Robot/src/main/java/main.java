import okhttp3.*;

import java.io.IOException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static api.jisuapi.tangshi.Search.Get;

public class main {
    private static String img() throws IOException {
        Scanner in = new Scanner(System.in);
        System.out.println("Type in the url of image:");
        System.out.println("For example: https://oss.neko.ooo/index.php/s/jHYPmwBwagK7nX7/download");
        String imgurl = in.nextLine();
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
        String returntext = response.body().string();
        //System.out.println(returntext);
        Pattern pattern = Pattern.compile("(?<=\"words\": \").*(?=\"}]})");
        Matcher matcher = pattern.matcher(returntext);
        String text = "";
        while (matcher.find()) {
            //System.out.println(matcher.group());
            text = matcher.group();
        }
        return text;
    }

    private static String SearchPoem() throws IOException {
        Scanner in = new Scanner(System.in);
        System.out.println("Type in the url of image:");
        System.out.println("For example: https://oss.neko.ooo/index.php/s/jHYPmwBwagK7nX7/download");
        String imgurl = in.nextLine();
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
        String returntext = response.body().string();
        //System.out.println(returntext);
        Pattern pattern = Pattern.compile("(?<=\"words\": \").*(?=\"}]})");
        Matcher matcher = pattern.matcher(returntext);
        String text = "";
        while (matcher.find()) {
            //System.out.println(matcher.group());
            text = matcher.group();
        }
        return text;
    }

    public static void main(String[] args) throws IOException {
        System.out.println("搜索文本请输入1；搜索图片中文字请输入2：");
        Scanner in = new Scanner(System.in);
        String type = in.nextLine();
        String text;
        if (type.equals("1")) {
            System.out.println("输入想要搜索的关键词：");
            text = in.nextLine();
        } else {
            text = img();
            System.out.println("图片中的文字是：" + text);
        }
        try {
            Get(text);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
