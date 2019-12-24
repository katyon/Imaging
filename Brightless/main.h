#pragma once

// �C���N���[�h
#include <windows.h>
#include <DxLib.h>

// �萔��`
#define STR_WINTTL				"Brightless"    // �E�B���h�E�^�C�g���i�C�ӂɐݒ�j
#define STR_MSGTTL_ASKFS		"�N������"
#define STR_MSG_ASKFS			"�t���X�N���[���ŋN�����܂����H"

enum GAME_STATE { Title, Choice, Game };

// �N���X��`
// ���C�����[�v�p�̐e�N���X
class SCENE
{
public:
    virtual void init(void) = 0;
    virtual void update(int GameTime) = 0;
    virtual void draw(int GameTime) = 0;
    virtual void end(void) = 0;
};

class TITLE :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class CHOICE :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class GAME :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};