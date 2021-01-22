package mavenpackage;

import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase; 
import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;
import org.bson.Document;
import static com.mongodb.client.model.Filters.*;

public class db {
    MongoCollection<Document> collection;
    MongoClientURI uri;    
    MongoClient mongoClient;
    MongoDatabase database;
    Document userD;
    public void connect(){
    this.uri = new MongoClientURI("mongodb+srv://dbrdpatel30:Varu1004@bank.xtmgl.mongodb.net/<dbname>?retryWrites=true&w=majority");    
    this.mongoClient = new MongoClient(uri);
    this.database = mongoClient.getDatabase("Bank");
    this.collection = database.getCollection("userData");
    System.out.println("Connection was successfully established");
    };
    public boolean Live_connect(){
        if(this.database != null)
        return false;
            else 
        return true;
    }
    public void userData(user ex){
          userD = new Document("firstname", ex.getFirstName())
            .append("lastname", ex.getLastName())
            .append("Email", ex.getEmailId())
            .append("UserId", ex.getuserId())
            .append("Password",ex.getPassword())
            .append("hashSalt",ex.getSalt());
            collection.insertOne(userD);
            mongoClient.close();
    }
    public boolean isUser(String usr_name, String usr_pass)throws IllegalAccessException{
        System.out.println("Well heer it is correct");
        Document findIterable = collection.find(eq("UserId", usr_name)).first(); 
        user test = new user(findIterable.toJson());
        boolean correct =Pass_enc.verifyUserPassword(usr_pass,test.getPassword(),test.getSalt());
	    if(correct)
        System.out.println("Well 2nd part works");
        else
        System.out.println("Well 3 rd part also works");
        return true;
    }
    // 10 - 3 AM LCBO.
}