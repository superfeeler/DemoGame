#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
class GameManager
{
public:
	static GameManager *sharedGameManager();
	static void purgeGameManager();
	
	bool init();

	enum SceneId
	{
		SCENE_MENU, 
		SCENE_PLAY,
		SCENE_GAMEOVER
	};

	void runSceneWithId(SceneId id);

protected:
	GameManager(void);
	~GameManager(void);

private:
	static GameManager *mSharedGameManager;
};

#endif