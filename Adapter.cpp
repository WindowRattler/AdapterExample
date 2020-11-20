//BenjaminKramer
//11/20/2020


//An illustration for how an adapter
//design pattern would work for a
//music player
#include <iostream>
#include <string>

using namespace std;
//creating the initial MediaPlayer
class MediaPlayer {
public:
	virtual void play(string file_type, string file_name) = 0;
	virtual ~MediaPlayer(){}
};
//creating the AdvancedMediaPlayer
//to be able to read
class AdvancedMediaPlayer {
public:
	AdvancedMediaPlayer() {}
	virtual void playVLC(string file_name) = 0;
  virtual void playMP3(string file_name) = 0;
	virtual void playMP4(string file_name) = 0;
  virtual void playWAV(string file_name) = 0;

	virtual ~AdvancedMediaPlayer(){}
};
//VLCPlayer class
class VLCPlayer : public AdvancedMediaPlayer {
public:
	void playVLC(string file_name) {
		cout << "Playing VLC file. Name: " << file_name << "\n";
	}
  void playMP3(string file_name) {
		cout << "Playing MP3 file. Name: " << file_name << "\n";
	}
	void playMP4(string file_name) {
		cout << "Playing MP4 file. Name: " << file_name << "\n";
	}
  void playWAV(string file_name) {
		cout << "Playing WAV file. Name: " << file_name << "\n";
	}

	~VLCPlayer() {}
};
//MP3Player class
class MP3Player : public AdvancedMediaPlayer {
public:
	void playMP3(string file_name) {
		cout << "Playing MP3 file. Name: " << file_name << "\n";
	}
  void playMP4(string file_name) {
		cout << "Playing MP4 file. Name: " << file_name << "\n";
	}
	void playVLC(string file_name) {
	  cout << "Playing VLC file. Name: " << file_name << "\n";
	}
  void playWAV(string file_name) {
		cout << "Playing WAV file. Name: " << file_name << "\n";
	}

	~MP3Player() {}
};
//MP4Player class
class MP4Player : public AdvancedMediaPlayer {
public:
	void playMP4(string file_name) {
		cout << "Playing MP4 file. Name: " << file_name << "\n";
	}
  void playMP3(string file_name) {
		cout << "Playing MP3 file. Name: " << file_name << "\n";
	}
	void playVLC(string file_name) {
	  cout << "Playing VLC file. Name: " << file_name << "\n";
	}
  void playWAV(string file_name) {
		cout << "Playing WAV file. Name: " << file_name << "\n";
	}

	~MP4Player() {}
};
//WAVPlayer class
class WAVPlayer : public AdvancedMediaPlayer {
public:
	void playWAV(string file_name) {
		cout << "Playing WAV file. Name: " << file_name << "\n";
	}
  void playMP3(string file_name) {
		cout << "Playing MP3 file. Name: " << file_name << "\n";
	}
	void playMP4(string file_name) {
		cout << "Playing MP4 file. Name: " << file_name << "\n";
	}
  void playVLC(string file_name) {
	  cout << "Playing VLC file. Name: " << file_name << "\n";
	}

	~WAVPlayer() {}
};

//the media adapter
class MediaAdapter : public MediaPlayer {
	AdvancedMediaPlayer *advancedMusicPlayer;

public:
	MediaAdapter(string file_type) {
		if (file_type.compare("vlc") == 0) {
			advancedMusicPlayer = new VLCPlayer;
		} else if (file_type.compare("mp3") == 0) {
			advancedMusicPlayer = new MP3Player;
		} else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer = new MP4Player;
		} else if (file_type.compare("wav") == 0) {
			advancedMusicPlayer = new WAVPlayer;
		}
	}

	void play(string file_type, string file_name) {
		if (file_type.compare("vlc") == 0) {
			advancedMusicPlayer->playVLC(file_name);
		} else if (file_type.compare("mp3") == 0) {
			advancedMusicPlayer->playMP3(file_name);
		} else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer->playMP4(file_name);
		} else if (file_type.compare("wav") == 0) {
			advancedMusicPlayer->playWAV(file_name);
		}
	}

	~MediaAdapter() {
		delete advancedMusicPlayer;
	}
};

class AudioPlayer : public MediaPlayer {
	MediaAdapter *mediaAdapter;

public:
	void play(string file_type, string file_name) {
		// inbuilt support to play mp3 music files
		if (file_type.compare("mp3") == 0) {
			cout << "Playing MP3 file. Name: " << file_name << "\n";
		} else if (
			file_type.compare("vlc") == 0 ||
      file_type.compare("mp4") == 0 ||file_type.compare("wav") == 0) {
			mediaAdapter = new MediaAdapter(file_type);
			mediaAdapter->play(file_type, file_name);
			delete mediaAdapter;
		} else {
			cout << "Invalid media. " << file_type;
			cout << " format not supported";
			cout << "\n";
		}
	}
};
//main
int main() {
	AudioPlayer audioPlayer;

	audioPlayer.play("mp3", "beyond_the_horizon.mp3");
	audioPlayer.play("mp4", "alone.mp4");
	audioPlayer.play("vlc", "far_far_away.vlc");
  audioPlayer.play("wav", "stronger.wav");
	audioPlayer.play("avi", "mind_me.avi");
}
