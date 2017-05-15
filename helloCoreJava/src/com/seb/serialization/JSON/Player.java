package com.seb.serialization.JSON;

import com.fasterxml.jackson.annotation.*;

@JsonAutoDetect
public class Player {
	
	@JsonProperty("name") 
	private String name;
	@JsonProperty("position") 
	private String position;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public String getPosition() {
		return position;
	}
	public void setPosition(String position) {
		this.position = position;
	}
	
}
