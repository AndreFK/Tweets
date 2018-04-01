
package tweet;

import java.io.*;

import twitter4j.*;
import java.util.ArrayList;
import twitter4j.conf.ConfigurationBuilder;

import java.util.List;
import twitter4j.Query;
import twitter4j.QueryResult;
import twitter4j.StatusUpdate;
import twitter4j.Twitter;
import twitter4j.TwitterFactory;
import twitter4j.User;
import twitter4j.Status;
import twitter4j.TwitterException;

import javax.swing.JOptionPane;
import javax.swing.*;
import jdk.nashorn.api.scripting.JSObject;
import sun.awt.FwDispatcher;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import java.util.Scanner;
import jdk.nashorn.api.scripting.JSObject;
import sun.awt.FwDispatcher;

public class Tweet {

    public static void main(String[] args) throws TwitterException, FileNotFoundException {

        ConfigurationBuilder cb = new ConfigurationBuilder();
        cb.setDebugEnabled(true);
        cb.setOAuthConsumerKey("t4BskFpLG4uascEadRdNwR948");
        cb.setOAuthConsumerSecret("7D44OTZh5a2JY9camKwGBU5hyvg2fUm87e9LVxKxmp3w4smAU3");
        cb.setOAuthAccessToken("2841807462-GMSK5i9dCM0GWkuS0tLuOZaQEkwPag93okUfuGz");
        cb.setOAuthAccessTokenSecret("5kEQBA8QO4CQPSHWHIdC6tnO6HS9lcQ1kv4plyliaSVq4");
        
        int contas=0, c=1;
        
        JSONObject obj = new JSONObject();
        
        String usuario = "RDKaizhar";
        
        TwitterFactory tf = new TwitterFactory(cb.build());
        twitter4j.Twitter twitter = tf.getInstance();
        
        File file = new File("Tweets.txt");
        PrintWriter OP =  new PrintWriter(file);
        OP.write("");
        
        //aqui se crea el archivo en donde se guardan las palabras que se buscan
        File palabra = new File("palabra.txt");
        PrintWriter PP = new PrintWriter(palabra);
        PP.write(usuario);
        
        /*en estas tres lineas de codigo aqui abajo es donde me da error. Si ponggo ese codigo como
        comentario funciona bien todo*/
        String palabra_word;
        Scanner sc= new Scanner(palabra);
        palabra_word = sc.next();
        
        
        //query es la palabra que se va a buscar en los tweets
        Query buscar = new Query(palabra_word);
        QueryResult result;
        result = twitter.search(buscar);
        
        //lo puse como lista normal por que si.
        List<Status> statuses = result.getTweets();
        User user = twitter.showUser(usuario);
        Status tweet = twitter.showStatus(20);
 
        for(Status status : statuses){
            OP.write(">>"+status.getText()+">>");
        }
        OP.close();


        /*for (int i = 0; i < tweets.size(); i++) {
            Status t = (Status) tweets.get(i);
            OP.println(t);
            OP.close();
        }*/

    }
}