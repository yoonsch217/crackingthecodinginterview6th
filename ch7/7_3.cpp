
class Jukebox{
	private:
		CDPlayer cdPlayer;
		User user;
		set<CD> cdCollection;
		SongSelector ts;

	public:
		Jukebox(CDPlayer cdPlayer, User user, set<CD> cdCollection, SongSelector ts){

		}

		Song getCurrentSong(){return ts.getCurrentSong();}
		void setUser(User u){this.user = u;}
};

class CDPlayer{
	private:
		Playlist p;
		CD c;

	public:
		CDPlayer(CD c, Playlist p){

		}

		void playSong(Song s){

		}

		Playlist getPlaylist(){return p;}
		void setPlaylist(Playlist p){ this.p = p;}

		CD getCD(){ return c;}
		void setCD(CD c){this.c = c;}
};

class Playlist{
	private:
		Song song;
		Queue<Song> queue;
	public:
		Playlist(Song song, Queue<Song> queue){

		}

		Song getNextSToPlay(){
			return queue.peek();
		}

		void queueUpSong(Song s){queue.add(s);}

};

