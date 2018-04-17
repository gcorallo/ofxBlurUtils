#version 150

uniform sampler2DRect tex0;

uniform float blurAmntR;
uniform float blurAmntG;
uniform float blurAmntB;

uniform float gain;


in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{

    vec4 color = vec4( vec3(0.0), 1.0);
	
    color += 2.0 *texture(tex0, texCoordVarying);
    
    color.r += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntR * 1.0, 0.0)).r;
    color.r += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntR * -1.0, 0.0)).r;
    
    color.g += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntG * 1.0, 0.0)).g;
    color.g += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntG * -1.0, 0.0)).g;
    
    color.b += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntB * 1.0, 0.0)).b;
    color.b += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmntB * -1.0, 0.0)).b;
    
    color /= 4.0;
    
    color.a = 1.0;
    
    color.rgb *=gain;

    
    outputColor = color;//vec4(vec3(blurAmnt),1.0);
}
