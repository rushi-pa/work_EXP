package mavenpackage;

import org.json.*;

public class user {
	private String id;
	private String firstName;
	private String lastName;
	private String userId;
	private String EmailId;
	private String Password;
	private String hasSalt;

	public user() {
		firstName = null;
		lastName = null;
		userId = null;
		EmailId = null;
		Password = null;
		hasSalt = null;
		id = null;
	}

	public user(String jsoDocument) {
		JSONObject json;
		try {
			json = new JSONObject(jsoDocument);
			try {
				this.firstName = (String) json.get("firstname");
			} catch (JSONException e) {
				e.printStackTrace();
			}
			try {
				this.lastName = (String) json.get("lastname");
			} catch (JSONException e) {
				e.printStackTrace();
			}
			try {
				this.EmailId = (String) json.get("Email");
			} catch (JSONException e) {
				e.printStackTrace();
			}
			try {
				this.Password = (String) json.get("Password");
			} catch (JSONException e) {
				e.printStackTrace();
			}
			try {
				this.hasSalt = (String) json.get("hashSalt");
			} catch (JSONException e) {
				e.printStackTrace();
			}
			try {
				this.userId = (String) json.get("UserId");
			} catch (JSONException e) {
				e.printStackTrace();
			}
		} catch (JSONException e) {
			e.printStackTrace();
		}
		// this is just an example assuming your xml had a Name Node
		
  }

	public user(String fName, String lName, String userId, String depart, String Password) {
		this.firstName = fName;
		this.lastName = lName;
		this.userId = userId;
        this.EmailId = depart;
        this.Password = Password;
	}
	public String getFirstName() {
		return this.firstName;
    }
    public String getPassword() {
		return this.Password;
    }
    public void setPassword(String Password) {
    setSalt(Pass_enc.getSalt(30));
	this.Password= Pass_enc.generateSecurePassword(Password,hasSalt);
	System.out.println(this.Password);
	}
	public String getSalt() {
		return this.hasSalt;
    }
    public void setSalt(String Salt) {
		this.hasSalt = Salt;
	}
	public String getId() {
		return this.id;
    }
    public void setid(String id) {
		this.id =id;
	}
	public String getLastName() {
		return this.lastName;
	}	
	public String getuserId() {
		return this.userId;
	}
	public String getEmailId() {
		return this.EmailId;
	}
	public String getName() {
		return this.firstName + " " + this.lastName;
	}
	public void setFirstName(String fName) {
		this.firstName = fName;
	}
	public void setLastName(String lName) {
		this.lastName = lName;
	}
	public void setuserId(String userId) {
		this.userId = userId;
	}
	public void setEmailId(String depart) {
		this.EmailId = depart;
	}	
}