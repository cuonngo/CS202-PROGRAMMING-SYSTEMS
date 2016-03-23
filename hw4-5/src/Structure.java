import java.util.Scanner;
class Util
{
	protected Scanner input;
	public Util()
	{
		input = new Scanner(System.in);
	}
}
class LLLi
{
	private LLLnode head;
	public LLLi(){
		this.head = null;
	}
	
	public void insert(String tit, String art, String alb)
	{
		LLLnode temp = new music(tit, art, alb);
		if(head == null)
		{
			temp.setNext(null);
			head = temp;
			return;
		}
		temp.setNext(head);
		head = temp;
	}
	
	public void display_all()
	{
		display_all(head);
	}
	
	protected void display_all(LLLnode head)
	{
		if(head == null)
			return;
		head.display();
		display_all(head.getNext());
	}
	
	public int compare(String name)
	{
		song temp = (song)(this.head);
		return temp.getArtist().compareTo(name);
	}
	
	protected void remove(String tit)
	{
		LLLnode current = head;
		LLLnode previous = current;
		while(current != null && !current.getTitle().equals(tit))
		{
			previous = current;
			current = current.getNext();
		}
		if(current == null)
		{
			System.out.println("Cannot find title: " + tit);
			return;
		}
		else if(current == head)
			head = current.getNext();
		else
			previous.setNext(current.getNext());
		current.setNext(null);
	}
	public int count()
	{
		return count(head);
	}
	
	protected int count(LLLnode head)
	{
		if(head == null)
			return 0;
		return count(head.getNext()) + 1;
	}
	
	public LLLnode retrieve(String tit)
	{
		return retrieve(head, tit);
	}
	
	protected LLLnode retrieve(LLLnode head, String tit)
	{
		if(head == null)
		{
			System.out.println("NOt Found");
			return null;
		}
		else if(head.getTitle().equals(tit))
		{
			System.out.println("Found");
			return head;
		}
		return retrieve(head.getNext(), tit);
	}
}

class BSTnode
{
	protected LLLi list;
	protected BSTnode right;
	protected BSTnode left;
	
	BSTnode(String tit, String art, String alb)
	{
		list = new LLLi();
		list.insert(tit, art, alb);
		this.left = null;
		this.right = null;
	}
	
	public BSTnode getRight()
	{
		return this.right;
	}
	
	public BSTnode getLeft()
	{
		return this.left;
	}
	
	public void setRight(BSTnode right)
	{
		this.right = right;
	}
	
	public void setLeft(BSTnode left)
	{
		this.left = left;
	}
	
	public int compare(String name)
	{
		return this.list.compare(name);
	}
}

class BST extends Util
{
	private BSTnode root;
	public BST()
	{
		root = null;
	}
	
	public void insert()
	{
		String title = new String();
		String artist = new String();
		String album = new String();
		
		System.out.println("Enter Title: ");
		title = input.nextLine();
		System.out.println("Enter Artist: ");
		artist = input.nextLine();
		System.out.println("Enter Album: ");
		album = input.nextLine();
		root = insert(root, title, artist, album);
	}
	
	protected BSTnode insert(BSTnode root, String tit, String art, String alb)
	{
		if(root == null)
		{
			root = new BSTnode(tit, art, alb);
			return root;
		}
		else if(root.list.compare(art) == 0)
			root.list.insert(tit, art, alb);
		else if(root.list.compare(art) < 0)
			root.setLeft(insert(root.getLeft(), tit, art, alb));
		else if(root.list.compare(art) > 0)
			root.setRight(insert(root.getRight(), tit, art, alb));
		return root;
	}
	
	public void display_all()
	{
		display_all(root);
	}
	
	protected void display_all(BSTnode root)
	{
		if(root == null)
			return;
		root.list.display_all();
		display_all(root.getLeft());
		display_all(root.getRight());
	}
	
	protected BSTnode successor(BSTnode root)
	{
		if(root == null)
			return null;
		else if(root.getRight() == null)
			return root;
		return successor(root.getRight());
	}
	
	public void remove(String tit, String art)
	{
		root = remove(root, tit, art);
	}
	
	protected BSTnode remove(BSTnode root, String tit, String art)
	{
		if(root == null)
			return null;
		else if(root.compare(art) == 0)
		{
			if(root.getLeft() != null && root.getRight() != null)
			{
				if(root.list.count() <= 1 && root.list.compare(tit) == 0)
				{
					BSTnode temp = successor(root);
					root.list = temp.list;
					root = remove(temp, tit, art);
					return root;
				}
				root.list.remove(tit);
			}
			else if(root.getLeft() != null && root.getRight() == null)
			{
				if(root.list.count() <= 1 && root.list.compare(tit) == 0)
					return root.getLeft();
				root.list.remove(tit);
			}
			else if(root.getRight() != null && root.getLeft() == null)
			{
				if(root.list.count() <= 1 && root.list.compare(tit) == 0)
					return root.getRight();
				root.list.remove(tit);
			}
			else if(root.getRight() == null && root.getLeft() == null)
			{
				if(root.list.count() <= 1 && root.list.compare(tit) == 0)
					return null;
				root.list.remove(tit);
			}
		}
		else if(root.compare(art) < 0)
			root.setLeft(remove(root.getLeft(), tit, art));
		else if(root.compare(art) > 0)
			root.setRight(remove(root.getRight(), tit, art));
		return root;
	}
	
	public LLLnode retrieve(String tit, String art)
	{
		LLLnode temp = retrieve(root, tit, art);
		return temp;
	}

	protected LLLnode retrieve(BSTnode root, String tit, String art)
	{
		if(root == null)
			return null;
		if(root.list.compare(art) == 0)
			return root.list.retrieve(tit);
		else if(root.list.compare(art) < 0)
			return retrieve(root.getLeft(), tit, art);
		else if(root.list.compare(art) > 0)
			return retrieve(root.getRight(), tit, art);
		return null;
	}
	
}