#version 150

in vec2 texCoordVarying;
out vec4 outputColor;
uniform int mode;

void main()
{
    
    vec2 resolution = vec2(1024.0,768.0);
    vec2 uv = gl_FragCoord.xy/resolution;
    vec4 color;
    float v;
    if(mode == 0){
        v = smoothstep(.0, .8, uv.y);
    }
    else if(mode == 1){
    
        v = distance(vec2(0.5), uv);
        v = smoothstep(.25, .6, v);
    }
    
    color = vec4(vec3(v), 1.0);
    
    outputColor = color;//vec4(vec3(blurAmnt),1.0);
}
