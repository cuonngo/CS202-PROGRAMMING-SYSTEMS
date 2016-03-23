import java.util.Random;
class array
{
	protected song [] listArray;
	protected int size = 100;
	
	array()
	{
		listArray = new song[size];
		for(int i = 0; i < size; ++i)
		{
			listArray[i] = null;
		}
	}
	
	public void insert(BST tree, String tit, String art)
	{
		for(int i = 0; i < size; ++i)
		{
			if(listArray[i] == null)
			{
				listArray[i] = (song)(tree.retrieve(tit, art));
				return;
			}
		}
	}
	
	public void display()
	{
		for(int i = 0; i < size; ++i)
		{
			if(listArray[i] != null)
				listArray[i].display();
			else
				break;
		}
	}

	public void remove(String tit)
	{
		for(int i = 0; i < size; ++i)
		{
			if(listArray[i] != null && listArray[i].compare(tit))
			{
				for(int j = i; j < size - 1; ++j)
					listArray[j] = listArray[j + 1];
			}
		}
	}
	
	public boolean isFull()
	{
		if(listArray[2] != null)
			return true;
		return false;
	}
	
	public int count()
	{
		int count = 0;
		for(int i = 0; i < size; ++i)
		{
			if(listArray[i] != null)
				++count;
			else
				break;
		}
		return count;
	}
	public void shuffle()
	{
		int pickedNumber;
		Random rand = new Random();
		for(int i = 0; i < 20; ++i)
		{
			if(count() == 0)
				break;
			song temp = listArray[0];
			pickedNumber = rand.nextInt(count());
			listArray[0] = listArray[pickedNumber];
			listArray[pickedNumber] = temp;
		}
			
	}
}

class playNode extends array
{
	protected playNode next;
	playNode()
	{
		this.next = null;
	}
	public playNode getNext()
	{
		return this.next;
	}
	public void setNext(playNode next)
	{
		this.next = next;
	}
}


class playlist extends Util
{
	private playNode head;
	public playlist()
	{
		this.head = new playNode();
	}
	
	public void insertList(BST obj)
	{
		String title = new String();
		String artist = new String();
		playNode current = head;
		
		System.out.println("Enter Title: ");
		title = input.nextLine();
		System.out.println("Enter Artist: ");
		artist = input.nextLine();

		current.insert(obj, title, artist);
		
	}
	
	public void display_all()
	{
		head.shuffle();
		display_all(head);
	}
	
	protected void display_all(playNode head)
	{
		if(head == null || head.count() == 0)
			return;
		head.display();
		display_all(head.getNext());
	}
	public void remove(String tit)
	{
		head.remove(tit);
	}
	
}