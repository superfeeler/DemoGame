#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__
class SoundManager
{
public:
	static SoundManager *sharedSoundManager();
	static void purgeSharedSoundManager();

	void playMusic();
	void stopMusic();

	void playLaserSFX();
	void playHitSFX();

protected:
	SoundManager(void);
	~SoundManager(void);

	bool init();

private:
	static SoundManager *mSharedSoundManager;

};

#endif