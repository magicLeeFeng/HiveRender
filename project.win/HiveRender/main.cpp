#include "../../Class/AppDelegate.h"
#include "../Hive/Platform/Win/esUtil.h"
#include "../Hive/Platform/Win/esUtil_win.h"

typedef struct
{
	// Handle to a program object
	GLuint programObject;

	// VertexBufferObject Ids
	GLuint vboIds[2];

	// VertexArrayObject Id
	GLuint vaoId;

} UserData;


int Init ( ESContext *esContext )
{
	UserData *userData = (UserData*)esContext->userData;
	AppDelegate::getInstance()->run();
	return GL_TRUE;
}

void Draw ( ESContext *esContext )
{
// 	UserData *userData = (UserData*)esContext->userData;
// 	glViewport ( 0, 0, esContext->width, esContext->height );
	AppDelegate::getInstance()->draw();
}

void Shutdown ( ESContext *esContext )
{
	UserData *userData = (UserData*)esContext->userData;
	
	glDeleteProgram ( userData->programObject );
	glDeleteBuffers ( 2, userData->vboIds );
	glDeleteVertexArrays ( 1, &userData->vaoId );
}

int esMain ( ESContext *esContext )
{
	esContext->userData = malloc ( sizeof ( UserData ) );

	esCreateWindow ( esContext, "VertexArrayObjects", 500, 500, ES_WINDOW_RGB );
	UserData *userData = (UserData*)esContext->userData;
	
	glViewport ( 0, 0, esContext->width, esContext->height );
	if ( !Init ( esContext ) )
	{
		return GL_FALSE;
	}

	esRegisterShutdownFunc ( esContext, Shutdown );
	esRegisterDrawFunc ( esContext, Draw );

 	return GL_TRUE;
}

void WinLoop ( ESContext *esContext )
{
	MSG msg = { 0 };
	int done = 0;
	DWORD lastTime = GetTickCount();

	while ( !done )
	{
		int gotMsg = ( PeekMessage ( &msg, NULL, 0, 0, PM_REMOVE ) != 0 );
		DWORD curTime = GetTickCount();
		float deltaTime = ( float ) ( curTime - lastTime ) / 1000.0f;
		lastTime = curTime;

		if ( gotMsg )
		{
			if ( msg.message == WM_QUIT )
			{
				done = 1;
			}
			else
			{
				AppDelegate::getInstance()->update();
				TranslateMessage ( &msg );
				DispatchMessage ( &msg );
			}
		}
		else
		{
			SendMessage ( esContext->eglNativeWindow, WM_PAINT, 0, 0 );
		}

		// Call update function if registered
		if ( esContext->updateFunc != NULL )
		{
			esContext->updateFunc ( esContext, deltaTime );
		}
	}
}


int main()
{
	ESContext esContext;

	memset ( &esContext, 0, sizeof ( ESContext ) );

	if ( esMain ( &esContext ) != GL_TRUE )
	{
		return 1;
	}

	WinLoop ( &esContext );

	if ( esContext.shutdownFunc != NULL )
	{
		esContext.shutdownFunc ( &esContext );
	}

	if ( esContext.userData != NULL )
	{
		free ( esContext.userData );
	}

	return 0;
}