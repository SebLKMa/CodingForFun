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
	public void makeBareHttpRequest() throws IOException {
		final URL url = new URL("http", "www.google.com", "/");
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
	
}
