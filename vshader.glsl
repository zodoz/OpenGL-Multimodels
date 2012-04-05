attribute  vec4 vPosition;
attribute  vec3 vColor;
varying vec4 color;

//uniform mat4 model_view;
uniform mat4 projection;

void
main()
{
    //gl_Position = projection * model_view * vPosition / vPosition.w;
    gl_Position = projection * vPosition / vPosition.w;
    color = vec4( vColor, 1.0 );
}
