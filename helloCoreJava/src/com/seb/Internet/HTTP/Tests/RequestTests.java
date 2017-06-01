package com.seb.Internet.HTTP.Tests;

import static org.junit.Assert.*;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

import org.junit.Test;

import org.apache.commons.io.IOUtils;

public class RequestTests {

	@Test
	public void makeBareHttpRmakeBareHttpRequestequest() throws IOException {
		//final URL url = new URL("https", "www.google.com.sg", "/");
		//final URL url = new URL("http", "localhost:80", "/");
		final URL url = new URL("http://localhost:80/");
		final HttpURLConnection connection = (HttpURLConnection)url.openConnection();
		connection.setRequestMethod("GET");

		final InputStream responseInputStream = connection.getInputStream();
		final int responseCode = connection.getResponseCode();
		final String response = IOUtils.toString(responseInputStream);
		
		responseInputStream.close();
		System.out.printf("Response code: [%d]%n", responseCode);
		assertEquals(200, responseCode);
		System.out.printf("Response received: [%s]%n", response);		
	}
	
	public static void main(String[] args) {
		RequestTests myTests = new RequestTests();
		try {
			myTests.makeBareHttpRmakeBareHttpRequestequest();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
