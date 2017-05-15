package com.seb.serialization.JSON;

import static org.junit.Assert.*;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

import org.junit.Test;
//import com.fasterxml.jackson.core.JsonGenerationException;
//import com.fasterxml.jackson.databind.JsonMappingException;
import com.fasterxml.jackson.annotation.*;
import com.fasterxml.jackson.databind.ObjectMapper;

@JsonAutoDetect
public class Team {
	
	@JsonProperty("name")
	private String name;
	@JsonProperty("dateFounded") 
	private String dateFounded;
	@JsonProperty("players") 
	private List<Player> players;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getDateFounded() {
		return dateFounded;
	}
	
	public void setDateFounded(String dateFounded) {
		this.dateFounded = dateFounded;
	}

	public List<Player> getPlayers() {
		return players;
	}

	public void setPlayers(List<Player> players) {
		this.players = players;
	}

	@Test
	public void readJson() throws IOException {
		final ObjectMapper mapper = new ObjectMapper();
		final String jsonFile = "C:\\Temp\\team.json";
		//final Team myTeam = mapper.readValue(getClass().getResourceAsStream(json), Team.class);
		final Team myTeam = mapper.readValue(new File(jsonFile), Team.class);
		
		assertEquals(2, myTeam.getPlayers().size());
	}
	
	@Test
	public void writeJson() throws IOException {
		final Player p1 = new Player();
		p1.setName("who cares");
		p1.setPosition("Engineer");
		
		final Player p2 = new Player();
		p2.setName("nobody");
		p2.setPosition("QA");
		
		final Team myTeam = new Team();
		myTeam.setName("A-Team");
		myTeam.setPlayers(Arrays.asList(p1, p2));
		
		final ObjectMapper mapper = new ObjectMapper();
		final File jsonFile = new File("C:\\Temp\\teamNew.json");
		mapper.writeValue(jsonFile, myTeam);
		
		assertTrue(jsonFile.exists());
	}
	
}
