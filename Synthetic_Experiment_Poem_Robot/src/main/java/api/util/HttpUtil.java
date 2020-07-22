package api.util;

import javax.net.ssl.HttpsURLConnection;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.Map;

public class HttpUtil {
	private static String USER_AGENT = "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0; SLCC1; .NET CLR 2.0.50727; .NET CLR 3.0.04506; customie8)";

	// HTTP GET request
	public static String sendGet(String url, String charset) throws Exception {
		URL realurl = new URL(url);
		HttpURLConnection con = (HttpURLConnection) realurl.openConnection();

		// optional default is GET
		con.setRequestMethod("GET");

		// add request header
		con.setRequestProperty("User-Agent", USER_AGENT);

		// int responseCode = con.getResponseCode();
		// System.out.println("Response Code : " + responseCode);

		BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream(), charset));
		String inputLine;
		StringBuffer result = new StringBuffer();
		while ((inputLine = in.readLine()) != null) {
			result.append(inputLine);
			result.append("\r\n");
		}
		in.close();
		con.disconnect();
		return result.toString();
	}

	// HTTP POST request
	@SuppressWarnings("deprecation")
	public static String sendPost(String url, Map<String, String> param, String charset) throws Exception {
		URL realurl = new URL(url);
		HttpsURLConnection con = (HttpsURLConnection) realurl.openConnection();

		con.setRequestMethod("POST");
		// add reuqest header
		con.setRequestProperty("User-Agent", USER_AGENT);
		// con.setRequestProperty("Accept-Language", "en-US,en;q=0.5");

		// String urlParameters =
		// "sn=C02G8416DRJM&cn=&locale=&caller=&num=12345";
		StringBuffer buffer = new StringBuffer();
		if (param != null && !param.isEmpty()) {
			for (Map.Entry<String, String> entry : param.entrySet()) {
				buffer.append(entry.getKey()).append("=").append(URLEncoder.encode(entry.getValue(), charset))
						.append("&");
			}
		}
		buffer.deleteCharAt(buffer.length() - 1);
		// Send post request
		con.setDoOutput(true);
		DataOutputStream wr = new DataOutputStream(con.getOutputStream());
		wr.writeBytes(buffer.toString());
		wr.flush();
		wr.close();
		// int responseCode = con.getResponseCode();
		// System.out.println("Post parameters : " + urlParameters);
		// System.out.println("Response Code : " + responseCode);

		BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream(), charset));
		String inputLine;
		StringBuffer result = new StringBuffer();
		while ((inputLine = in.readLine()) != null) {
			result.append(inputLine);
			result.append("\r\n");
		}
		in.close();
		con.disconnect();
		return result.toString();
	}
}
