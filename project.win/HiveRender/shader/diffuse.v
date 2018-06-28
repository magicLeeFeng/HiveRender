precision mediump float;
varying vec4 vColor;
void main(){
	vec4 _worldNormal = normalize(_object2World * vec4(ARNORMAL,0));
	vec3 worldNormal = vec3(_worldNormal.x,_worldNormal.y,_worldNormal.z);
	vec3 lightpos = normalize(_LightPosition0 * -1.0);
	float cosTheta = clamp(dot( worldNormal,lightpos),0.0,1.0);
	vec3 _color = AR_AMBIENT_COLOR + _LightColor0 * cosTheta;
	vColor = vec4(_color,1);
	gl_Position = ARMVP * ARPosition;
}