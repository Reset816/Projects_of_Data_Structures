package api.jisuapi.tangshi;

import api.util.HttpUtil;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import java.net.URLEncoder;

public class Search {

    public static final String APPKEY = "8f1318e8842aba0a";// 你的appkey
    public static final String URL = "https://api.jisuapi.com/tangshi/search";
    //public static final String keyword = "白日";// utf-8

    public static void Get(String keyword) throws Exception {
        String result = null;
        String url = URL + "?appkey=" + APPKEY + "&keyword=" + URLEncoder.encode(keyword, "utf-8");

        try {
            result = HttpUtil.sendGet(url, "utf-8");
            JSONObject json = JSONObject.fromObject(result);
            if (json.getInt("status") != 0) {
                System.out.println(json.getString("msg"));
            } else {
                JSONObject resultarr = json.optJSONObject("result");
                String total = resultarr.getString("total");
                String pagenum = resultarr.getString("pagenum");
                String pagesize = resultarr.getString("pagesize");
                System.out.println(total + " " + pagenum + " " + pagesize);
                JSONArray list = resultarr.optJSONArray("list");
                for (int i = 0; i < list.size(); i++) {
                    JSONObject obj = list.optJSONObject(i);
                    String title = obj.getString("title");
                    String type = obj.getString("type");
                    String content = obj.getString("content");
                    String explanation = obj.getString("explanation");
                    String appreciation = obj.getString("appreciation");
                    String author = obj.getString("author");
                    System.out.println(
                            title + " " + type + " " + content + " " + explanation + " " + appreciation + " " + author);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}