abstract class LLLnode{
	protected LLLnode next;
	LLLnode()
	{
		this.next = null;
	}
	public LLLnode getNext()
	{
		return this.next;
	}
	public void setNext(LLLnode next)
	{
		this.next = next;
	}
	public abstract void display();
	public abstract String getTitle();
	public abstract String getArtist();
	public abstract String getAlbum();
}

class song extends LLLnode {
	protected String Artist;
	protected String Title;
	protected String Album;
	public song()
	{
		this.Artist = new String();
		this.Title = new String();
		this.Album = new String();
	}
	public song(String tit, String art, String alb)
	{
		this.Title = tit;
		this.Artist = art;
		this.Album = alb;
	}
	public song(song obj)
	{
		this.Title = obj.getTitle();
		this.Artist = obj.getArtist();
		this.Album = obj.getAlbum();
	}
	public void display()
	{
	}
	public String getTitle()
	{
		return Title;
	}
	public String getArtist()
	{
		return Artist;
	}
	public String getAlbum()
	{
		return Album;
	}
	public boolean compare(String tit)
	{
		return(this.getTitle().equals(tit));
	}
}

class music extends song
{
	public music()
	{
		super();
	}
	public music(String  tit, String art, String alb)
	{
		super(tit, art, alb);
	}
	public music(music obj)
	{
		super(obj);
	}
	public void display()
	{
		System.out.println("Song: " + Title + "\tArtist: " + Artist + "\tAlbum: " + Album);
	}
}

class ringtone extends song
{
	public ringtone()
	{
		super();
	}
	public ringtone(String  tit, String art, String alb)
	{
		super(tit, art, alb);
	}
	public ringtone(music obj)
	{
		super(obj);
	}
	public void display()
	{
		System.out.println("Ringtone: " + Title + "\tArtist: " + Artist + "\tAlbum: " + Album);
	}
}
