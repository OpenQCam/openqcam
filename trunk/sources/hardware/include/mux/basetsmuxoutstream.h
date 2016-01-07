#ifndef _BaseTSMuxOutStream_H
#define _BaseTSMuxOutStream_H

//common
#include "common.h"
//thelib
//#include "mediaformats/mp4/baseatom.h"
#include "streaming/baseoutstream.h"
#include "interface/deviceinterface.h"
#include "netio/netio.h"
//hardware
#include "video/videodefine.h"
#include "video/basevideostream.h"


typedef enum {
  MP4MUX_REG_VIDEO=0x01,
  MP4MUX_REG_AUDIO=0x02,
} _MUX_STATUS;

typedef enum {
  MUX_STOP_RECORD=0x00,
  MUX_START_RECORD,
  MUX_OPEN_FILE_ERR,
  MUX_UPDATE_HEADER_ERR,
  MUX_UPDATE_MEDIA_ERR,
  MUX_NO_STORAGE_SPACE,
} MUX_STATE;

class WriteMP4Document;
class BaseStorageDevice;

class BaseTSMuxOutStream
: public BaseOutStream,
  public ISystemCommandCallback
{

private:
  uint64_t _duration;
  double _videoTimeStamp;//keep last timestamp
  double _audioTimeStamp;
  uint8_t _status;
  uint32_t _frameCounter;
  uint32_t _keyframeCounter;
  uint32_t _fileCounter;
  uint32_t _maxFrames;
  //vector<AtomUpdateInfo> _videoInfo;
  uint8_t *_frameBuffer;
  bool _storeDirty;
  uint32_t _frameBufferSize;
  bool tsFileIsOpen;
  //uint64_t video_pts;
  uint32_t cacheDuration;
  char cacheOutputName[64];
  double video_time;
  bool BuildTSDocument(string name, uint64_t creationTime, uint32_t maxFrames);

protected:
  MUX_STATE _muxState;
  //WriteMP4Document* _mp4file;
  double _firstFrameTime, _lastFrameTime;
  BaseInStream *_pVideoStream;
  BaseInStream *_pAudioStream;
  bool _updated;
  BaseStorageDevice *_pStorageDevice;
  virtual bool UpdateInfo(double currentTime);

public:
  BaseTSMuxOutStream(StreamsManager *pStreamsManager, string name);
  virtual ~BaseTSMuxOutStream();
  virtual bool SignalPlay(double &absoluteTimestamp, double &length);
  virtual bool SignalStop();
  virtual bool SignalPause();
  virtual bool SignalResume();
  virtual bool SignalSeek(double &absoluteTimestamp);
  virtual bool IsCompatibleWithType(uint64_t type);
  virtual void SignalAttachedToInStream();
  virtual void SignalDetachedFromInStream();
  virtual void SignalStreamCompleted();
  virtual void OnDeviceVideoData(DeviceData& data);

  virtual bool Initialize();
  virtual void RegisterStream(BaseInStream *stream);
  virtual void UnRegisterStream(BaseInStream *stream);
  virtual bool FeedData(uint8_t *pData, uint32_t dataLength, uint32_t processedLength, uint32_t totalLength, double absoluteTimestamp, bool isAudio);
  virtual bool StartRecord(string fileName, uint32_t maxFrames);
  virtual bool StopRecord();
  virtual uint8_t GetStatus();
  bool IsRecording();
  bool IsError();
  virtual void UnRegisterAllStream();
  virtual void OnCmdFinished(uint32_t msgId, uint8_t *pData,
                             uint32_t dataLength);

  //virtual bool SignalAudioPlay()=0;
  //virtual bool SignalAudioStop()=0;
};

#endif /* _BaseTSMuxOutStream_H */
