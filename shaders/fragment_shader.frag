uniform vec2 lightPos;

void main()
{
    if (lightPos[0] < gl_FragCoord.x + 50 && lightPos[0] > gl_FragCoord.x - 50 && lightPos[1] > gl_FragCoord.y - 50 && lightPos[1] < gl_FragCoord.y + 50)
    {
	gl_FragColor = gl_Color;
    }
    else
    {
	gl_FragColor = vec4(0, 0, 0, 1);   
    }
}