//
// Created by Masayuki IZUMI on 10/5/16.
//

#ifndef CIPOINTCLOUDVIEWERAPP_CLOUDSRENDERER_H
#define CIPOINTCLOUDVIEWERAPP_CLOUDSRENDERER_H

#include "cinder/app/AppBase.h"

#include "Clouds.h"
#include "renderer/Renderer.h"

namespace renderer {
namespace cloud {

class CloudsRenderer : public Renderer {
public:
  CloudsRenderer(
    ci::app::AppBase *app,
    const std::shared_ptr<Clouds> &clouds
  );

  void update() override;
  void render() override;


private:
  const std::unique_ptr<Renderer> points_renderer_;
  const std::unique_ptr<Renderer> vertices_renderer_;
  const std::shared_ptr<Clouds> clouds_;
};

}
}

#endif //CIPOINTCLOUDVIEWERAPP_CLOUDSRENDERER_H
