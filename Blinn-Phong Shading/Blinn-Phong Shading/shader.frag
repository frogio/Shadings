// 보간된 난반사, 주변광, 법선벡터, 반벡터
varying vec4 diffuse, ambient;
varying vec3 normal, halfVector;

void main(){
	vec3 n, halfV, lightDir;
	// 난반사를 위한 내적, 정반사를 위한 내적
	float NdotL, NdotHV;
	
	// 빛 벡터
	lightDir = vec3(gl_LightSource[0].position);

	vec4 color = ambient;

	// n은 프래그먼트 픽셀의 노말
	n = normalize(normal);

	// 법선과 광원벡터의 내적을 구하여 난반사 광강도를 계산한다.
	NdotL = max(dot(n, lightDir), 0.0);
	if(NdotL > 0.0){
		color += diffuse * NdotL * 0.1;
		halfV = normalize(halfVector);
		// 반 벡터를 구한 뒤
		// 정반사 강도를 구한다.
		NdotHV = max(dot(n, halfV), 0.0);
		color += gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(NdotHV, gl_FrontMaterial.shininess);
	}

	gl_FragColor = color;
}