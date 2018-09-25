#ifndef NGLSCENE_H_
#define NGLSCENE_H_

#include <ngl/Transformation.h>
#include <ngl/Vec3.h>
#include "WindowParams.h"
#include <QEvent>
#include <QResizeEvent>
#include <QOpenGLWidget>
/// @file NGLScene.h
/// @brief a basic Qt GL window class for ngl demos
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/10/10
/// Revision History :
/// Initial Version 10/10/10 (Binary day ;-0 )
/// @class GLWindow
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
class NGLScene : public QOpenGLWidget
{
Q_OBJECT        // must include this if you use Qt signals/slots
public :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor for GLWindow
  /// @param [in] _parent the parent window to create the GL context in
  //----------------------------------------------------------------------------------------------------------------------
  NGLScene(QWidget *_parent );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor
  //----------------------------------------------------------------------------------------------------------------------
  ~NGLScene();
 public slots :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a slot to set the start rotation value signal sent from main window
  /// @param[in] _r the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setStartRotation(ngl::Vec3 _r){m_srotation=_r; update();}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a slot to set the end rotation value signal sent from main window
  /// @param[in] _r the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setEndRotation(ngl::Vec3 _r){m_erotation=_r; update();}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a slot to set the interpolation rotation value signal sent from main window
  /// @param[in] _r the value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setInterpolation(ngl::Real _v){m_interp=_v; update();}
 signals :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief emit a signal to to say that our value has changed
  /// @param[out] _s the string to emit
  //----------------------------------------------------------------------------------------------------------------------
    void changeStartQuat(QString _s);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief emit a signal to to say that our value has changed
  /// @param[out] _s the string to emit
  //----------------------------------------------------------------------------------------------------------------------
    void changeEndQuat(QString _s);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief emit a signal to to say that our value has changed
    /// @param[out] _s the string to emit
    //----------------------------------------------------------------------------------------------------------------------
    void changeInterpQuat(QString _s);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief emit a signal to clear the text box
    /// @param[out] _s the string to emit
    //----------------------------------------------------------------------------------------------------------------------
    void clearMatrixText();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief emit a signal to to say that our value has changed
    /// @param[out] _s the string to emit
    //----------------------------------------------------------------------------------------------------------------------
    void appendMatrixText(QString _s);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief emit a signal to to say that our value has changed
    /// @param[out] _s the string to emit
    //----------------------------------------------------------------------------------------------------------------------
    void updateInterpText(QString _s);
private :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the start rotation value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_srotation;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the end rotation value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_erotation;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the interpolation value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Real m_interp;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a projection matrix calculated once from the Util class this saves
  /// having a camera
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Mat4 m_projection;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a lookat matrix calculated once from the Util class this saves
  /// having a camera
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Mat4 m_lookAt;

protected:

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief  The following methods must be implimented in the sub class
  /// this is called when the window is created
  //----------------------------------------------------------------------------------------------------------------------
  void initializeGL();

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is called whenever the window is re-sized
  /// @param[in] _w the width of the resized window
  /// @param[in] _h the height of the resized window
  //----------------------------------------------------------------------------------------------------------------------
  void resizeGL(const int _w, const int _h );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is the main gl drawing routine which is called whenever the window needs to
  /// be re-drawn
  //----------------------------------------------------------------------------------------------------------------------
  void paintGL();

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our transform for objects
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Transformation m_transform;
private :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called every time a mouse is moved
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseMoveEvent ( QMouseEvent * _event );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is pressed
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------

  void mousePressEvent ( QMouseEvent *_event );

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is released
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseReleaseEvent (QMouseEvent *_event);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to load the matrix values to the shader
  //----------------------------------------------------------------------------------------------------------------------
  void loadMatricesToShader();


};

#endif
