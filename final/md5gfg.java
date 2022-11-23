import java.util.*;
import java.security.*;
import java.math.BigInteger;

public class md5gfg{
    public static String getmd5(String ip){
        try{
        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] mdig = md.digest(ip.getBytes());
        BigInteger n = new BigInteger(1, mdig);

        String hash = n.toString(16);
        while(hash.length() < 32)
            hash = "0"+hash;
        return hash;
        }
        catch (NoSuchAlgorithmException e){
            throw new RuntimeException(e);
        }
    }
    public static void main(String args[]){
        String s = "";
        Scanner in = new Scanner(System.in);
        System.out.print("Enter message: ");
        s = in.nextLine();
        String m = getmd5(s);
        System.out.println(m);
    }
}
