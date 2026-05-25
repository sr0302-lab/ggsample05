#include "gg.h"
using namespace gg;

#include "object.h"

//
// 頂点配列オブジェクトの作成
//
//   vertices: 頂点数
//   position: 頂点の二次元位置 (GLfloat[3] の配列)
//   lines: 線分数
//   index: 線分の頂点インデックス
//   戻り値: 作成された頂点配列オブジェクト名
//
// 以前のコード
GLuint createObject(GLuint vertices, const GLfloat(*position)[3], GLuint lines, const GLuint* index)
// 追加コード
GLuint createObject(
    GLuint vertices,
    const GLfloat(*position0)[3],
    const GLfloat(*position1)[3],
    GLuint lines,
    const GLuint* index
)
//
{
  // 頂点配列オブジェクト
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // 追加コード2
  // p0用の頂点バッファオブジェクト
  GLuint vbo0;
  glGenBuffers(1, &vbo0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo0);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[3]) * vertices, position0, GL_STATIC_DRAW);

  // layout(location = 0)のp0に送る
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  //

  // 追加コード3
  // p1用の頂点バッファオブジェクト
  GLuint vbo1;
  glGenBuffers(1, &vbo1);
  glBindBuffer(GL_ARRAY_BUFFER, vbo1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[3]) * vertices, position1, GL_STATIC_DRAW);

  // layout(location = 1)のp1に送る
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  //

  // インデックスバッファオブジェクト
  GLuint ibo;
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * lines, index, GL_STATIC_DRAW);

  // 頂点配列オブジェクトの結合を解除した後に頂点バッファオブジェクトとインデックスバッファオブジェクトの結合を解除する
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


  return vao;
}
