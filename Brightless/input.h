#pragma once
// �C���N���[�h ---------------------------------------------------------
#include "common.h"

// �萔 ----------------------------------------------------------------
enum Thumb
{
    Not,    // ���͂Ȃ�
    Up, Before_Upper_Right, Upper_Right, After_Upper_Right,     // �ォ��E
    Right, Before_Lower_Right, Lower_Right, After_Lower_Right,  // �E���牺
    Down, Before_Lower_Left, Lower_Left, After_Lower_Left,      // �����獶
    Left, Before_Upper_Left, Upper_Left, After_Upper_Left,      // �������
    Little_Up, Little_Right, Little_Down, Little_Left,      // �����炢�|���Ă鎞
    Little_Upper_Right, Little_Lower_Right, Little_Lower_Left, Little_Upper_Left,
    Roughly_Up, Roughly_Right, Roughly_Left, Roughly_Down   // ���̓��͂Ɋ֌W�Ȃ��e�㉺���E�����
};

/// InputClass How to
// 1.Input.h���C���N���[�h����
// 2. Input::GetInstance()�ŃC���X�^���X���o�R����public�֐����Ăяo���B
// ��j�@Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_Y);

class Input
{
public:
    // �V���O���g��
    static Input* GetInstance()
    {
        return instance;
    }
    static void Create();
    static void Destroy();

    // ������
    void Init();
    // ���͍X�V
    void Updata();
    // �������u�Ԃ���TRUE��Ԃ�
    bool GetKeyDown(int inputKey);
    // �������u�Ԃ���TRUE��Ԃ�(�S�ẴL�[)
    bool GetKeyDownAll(void);
    // �����Ă����TRUE��Ԃ�
    bool GetKey(int inputKey);
    // �������u�Ԃ���TRUE��Ԃ�
    bool GetButtonDown(PL_Num playerNum, int inputKey);
    // �������u�Ԃ���TRUE��Ԃ�(�S�Ẵ{�^��)
    bool GetButtonDownAll(PL_Num plNum);
    // �����Ă����TRUE��Ԃ�
    bool GetButton(PL_Num playerNum, int inputKey);
    // ���X�e�B�b�N��|���Ă�������̒l��Ԃ�
    bool GetLeftThumb(PL_Num plNum, int  LeftThumb);
    // �E�X�e�B�b�N��|���Ă�������̒l��Ԃ�
    bool GetRightThumb(PL_Num plNum, int  RightThumb);

private:
    XINPUT_STATE input[2] = {};
    char key[256] = {};// ���͏��
    char key_buf[256] = {};
    int button[2][16] = {};
    int ThumbLX[2] = {};
    int ThumbLY[2] = {};
    int ThumbRX[2] = {};
    int ThumbRY[2] = {};
    enum Input_State
    {
        Not, Down, Stay
    };
    enum Thumb_State
    {
        Zero, Mid, Max
    };

protected:


    Input() {};
    virtual ~Input() {};
    static Input* instance;
};