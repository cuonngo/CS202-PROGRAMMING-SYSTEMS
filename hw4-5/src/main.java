import java.util.Scanner;


public class main{
	public static void main(String[] args){
		BST newBST = new BST();
		playlist newPlaylist = new playlist();
		int num;
		
		do{
			num = menu();
			if(num == 1 || num == 2)
				newBST.insert();
			else if(num == 3)
				newBST.display_all();
			else if(num == 4 || num == 5)
				newPlaylist.insertList(newBST);
			else if(num == 6)
			{	
				Scanner input = new Scanner(System.in);
				String title = new String();
				System.out.println("Enter Title: ");
				title = input.nextLine();
				newPlaylist.remove(title);
			}	
			else if(num == 7)
				newPlaylist.display_all();
		}while(num != 8);
	}
	
	public static int menu()
	{
		Scanner input = new Scanner(System.in);
		input = new Scanner(System.in);
		int num;
		System.out.println("Pick one of the following number:\n" +
				"1. Insert song into library\n" +
				"2. Insert ringtone into library\n" +
				"3. Display library\n" +
				"4. Insert song into Playlist\n" +
				"5. Insert ringtone into Playlist\n" +
				"6. Remove a song/ringtone in Playlist\n" +
				"7. Display Playlist\n" +
				"8. Quit");
		num = input.nextInt();
		return num;
	}
}


