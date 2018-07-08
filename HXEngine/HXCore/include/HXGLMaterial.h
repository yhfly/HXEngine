#pragma once
#include "HXCommon.h"
#include "HXMaterial.h"
#include "vgl.h"

namespace HX3D
{
	class HXGLRenderable;
	class HXGLMaterial : public HXMaterial
	{
	public:
		HXGLMaterial(HXMaterialInfo* pMatInfo);
		~HXGLMaterial();
		
		void SetMaterialRenderState(HXGLRenderable* renderable);
		void SetShadowMapMaterialRenderState(HXGLRenderable* renderable);

		GLuint render_scene_prog;

		struct
		{
			GLint render_eye_pos_loc;
			GLint render_model_matrix_loc;
			GLint render_view_matrix_loc;
			GLint render_projection_matrix_loc;
			GLint render_mvp_matrix_loc;
			GLint render_shadow_matrix_loc;
		}render_scene_uniforms;

		int depth_texture_index;

		int test;
	};
}


