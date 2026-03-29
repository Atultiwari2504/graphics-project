import numpy as np
import pyglet
import moderngl

VERTEX_SHADER = """
#version 330
in vec3 in_pos;
in vec3 in_col;
out vec3 v_col;
void main() {
    gl_Position = vec4(in_pos, 1.0);
    v_col = in_col;
}
"""
FRAGMENT_SHADER = """
#version 330
in vec3 v_col;
out vec4 f_color;
void main() {
    f_color = vec4(v_col, 1.0);
}
"""

class SquareWindow(pyglet.window.Window):
    def __init__(self):
        super().__init__(600, 600, "Lesson 4: Indexed Square")
        self.ctx = moderngl.create_context()

        vertices = np.array([
            -0.5, -0.5, 0.0,  1.0,0.0,0.0,
             0.5, -0.5, 0.0,  0.0,1.0,0.0,
             0.5,  0.5, 0.0,  0.0,0.0,1.0,
            -0.5,  0.5, 0.0,  1.0,1.0,0.0,
        ], dtype='f4')
        indices = np.array([0,1,2, 2,3,0], dtype='u4')

        self.prog = self.ctx.program(vertex_shader=VERTEX_SHADER, fragment_shader=FRAGMENT_SHADER)
        self.vbo = self.ctx.buffer(vertices.tobytes())
        self.ibo = self.ctx.buffer(indices.tobytes())
        self.vao = self.ctx.vertex_array(self.prog, [(self.vbo, '3f 3f', 'in_pos', 'in_col')], self.ibo)

    def on_draw(self):
        self.ctx.clear(0.12, 0.12, 0.12)
        self.vao.render()

if __name__ == "__main__":
    SquareWindow()
    pyglet.app.run()
